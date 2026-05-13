// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameplayAbility.h"

FGameplayAbilityInfo::FGameplayAbilityInfo():
CD(0),
CostValue(0),
CostType(ECostType::MP),
IconMaterial(nullptr),
AbilityClass(nullptr)
{
}

FGameplayAbilityInfo::FGameplayAbilityInfo(float CD, ECostType CostType, float CostValue,
	UMaterialInstance* IconMaterial, TSubclassOf<UBaseGameplayAbility> AbilityClass):
CD(CD),
CostValue(CostValue),
CostType(CostType),
IconMaterial(IconMaterial),
AbilityClass(AbilityClass)
{
}

FGameplayAbilityInfo UBaseGameplayAbility::GetAbilityInfo(int level)
{
	UGameplayEffect* CDEffect = GetCooldownGameplayEffect();
	UGameplayEffect* CostEffect = GetCostGameplayEffect();
	float CD = 0;
	float CostValue = 0;
	ECostType CostType = ECostType::MP;
	if (CostEffect && CostEffect)
	{
		CDEffect->DurationMagnitude.GetStaticMagnitudeIfPossible(level, CD);
		
	}
	
	return FGameplayAbilityInfo();
}
