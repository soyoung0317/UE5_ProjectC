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
	// 입력액션과 태그를 매핑하기 
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
	// Enhanced Input의 Mapping Context를 의미 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;

	// 구조체 배열. 태그<>액션 매핑과 에디터에서 순서대로 띄워 수정할 수 있따. 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;

	// 배열을 순회하면서 매개변수와 같은 InputTag를 가진 구조체를 찾고, 그에 대응하는 UInputAction*을 반환한다. 
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
};
