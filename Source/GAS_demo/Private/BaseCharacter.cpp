// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	//一个AbilitySystemComponent的指针;this指针调用自己的函数FindComponentByClass来寻找自己身上的UAbilitySystemComponent类别的组件
	UAbilitySystemComponent* MyAbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	
	//如果成功在自己身上找到了UAbilitySystemComponent组件
	if (MyAbilitySystemComponent)
	{
		//使自己的UAbilitySystemComponent获取HP的数值变化委托，每当HP的数值发生变化时，就会触发OnHealthAttributeChanged函数
		//GetGameplayAttributeValueChangeDelegate是获取数值变化委托
		//变化的数值是UBaseAttributeSet::GetHPAttribute()，也就是HP
		//AddUObject把函数OnHealthAttributeChanged绑定到这个变化事件上
		MyAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UBaseAttributeSet::GetHPAttribute()).AddUObject(this, &ABaseCharacter::OnHealthAttributeChanged);
	}
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//每当HP发生变化时，数值变化委托触发这个函数，这个函数把新的HP值广播出去
void ABaseCharacter::OnHealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	//Data结构体包括oldvalue和newvalue，我们把newvalue广播出去；由于在前面定义的是单变量动态多播委托，所以只有一个参数
	HPChangeEvent.Broadcast(Data.NewValue);
}

FGameplayAbilityInfo ABaseCharacter::GameplayAbilityInfo(TSubclassOf<UBaseGameplayAbility> AbilityClass, int level)
{
	//获取角色身上的技能组件
	UAbilitySystemComponent* MyAbilitySystemComponent = this->FindComponentByClass<UAbilitySystemComponent>();
	
	//获取技能
	UBaseGameplayAbility* AbilityInstance = AbilityClass->GetDefaultObject<UBaseGameplayAbility>();
	
	//如果技能组件和技能都存在
	if (MyAbilitySystemComponent && AbilityInstance)
	{
		return AbilityInstance->GetAbilityInfo(level);
	}
		
		
	return FGameplayAbilityInfo(); 
}

