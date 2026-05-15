// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BaseGameplayAbility.generated.h"

//技能消耗的类型枚举
UENUM(BlueprintType)
enum class ECostType :uint8
{
	HP,
	MP,
	Strength
};


//USTRUCT(BlueprintType) 的意思是：这个 C++ 结构体类型可以被蓝图系统识别并作为一种蓝图类型使用。
USTRUCT(BlueprintType)
//技能信息结构体，包括CD，消耗类型（枚举类），消耗值，技能的图标材质，技能的类（比如Melee）
struct FGameplayAbilityInfo
{
	GENERATED_BODY();
	
	//所有变量都在蓝图中可读可编辑
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	float CD;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	ECostType CostType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	float CostValue;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	UMaterialInstance* IconMaterial;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AbilityInfo")
	//TSubclassOf是模板类，TSubclassOf<UBaseGameplayAbility>代表的是UBaseGameplayAbility的子类；我们的所有技能蓝图都是UBaseGameplayAbility的子类
	TSubclassOf<UBaseGameplayAbility> AbilityClass;
	
	FGameplayAbilityInfo();
	FGameplayAbilityInfo(float CD, ECostType CostType, float CostValue, UMaterialInstance* IconMaterial, TSubclassOf<UBaseGameplayAbility> AbilityClass);
};

UCLASS()
class GAS_DEMO_API UBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
	UMaterialInstance* IconMaterial;
	
public:
	//将函数暴露给蓝图
	UFUNCTION(BlueprintCallable, Category = "AbilityInfo")
	//获取技能属性信息函数，根据传进的技能等级获取技能的属性信息
	FGameplayAbilityInfo GetAbilityInfo(int level);
};
