// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAttributeSet.h"

#include "GameplayEffectExtension.h"

void UBaseAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	//Super代表该类的父类，这里UBaseAttributeSet的父类是UAttributeSet
	Super::PostGameplayEffectExecute(Data);
	
	//GetHPAttribute就是在头文件中用宏自动定义的函数
	if (Data.EvaluatedData.Attribute == GetHPAttribute())
	{
		SetHP(FMath::Clamp(GetHP(), 0.0, GetMaxHP()));
	}
	
	if (Data.EvaluatedData.Attribute == GetMPAttribute())
	{
		SetMP(FMath::Clamp(GetMP(), 0.0, GetMaxMP()));
	}
	
	if (Data.EvaluatedData.Attribute == GetStrengthAttribute())
	{
		SetStrength(FMath::Clamp(GetStrength(), 0.0, GetMaxStrength()));
	}
}
