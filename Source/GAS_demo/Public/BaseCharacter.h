// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "BaseCharacter.generated.h"
//声明单变量动态多播委托
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangeEvent, float, NewValue);

UCLASS()
class GAS_DEMO_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//将下一行的成员变量暴露给引擎的反射系统
	//BlueprintAssignable表示这个委托事件可以被蓝图监听
	UPROPERTY(BlueprintAssignable, Category = "Ability")
	FOnHealthChangeEvent HPChangeEvent;
	
	void OnHealthAttributeChanged(const FOnAttributeChangeData& Data);

};
