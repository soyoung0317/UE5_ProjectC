// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()

public:
	// �Է¾׼ǰ� �±׸� �����ϱ� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InputAction;

};
/**
 * 
 */
UCLASS()
class PROJECTC_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// Enhanced Input�� Mapping Context�� �ǹ� 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;

	// ����ü �迭. �±�<>�׼� ���ΰ� �����Ϳ��� ������� ��� ������ �� �ֵ�. 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;

	// �迭�� ��ȸ�ϸ鼭 �Ű������� ���� InputTag�� ���� ����ü�� ã��, �׿� �����ϴ� UInputAction*�� ��ȯ�Ѵ�. 
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
};
