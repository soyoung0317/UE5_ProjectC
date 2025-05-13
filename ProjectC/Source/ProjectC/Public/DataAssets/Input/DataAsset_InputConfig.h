// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DataAsset_InputConfig.generated.h"

/* --------- 변경사항 ---------
	UE에서 DA_Dataconfig파일이 열리지않고 인식되지 않아 Project Setting에 반영되지않음.
	따라서, EditDefaultsOnly -> EditAnywhere 로 변경하고, 

	UCLASS() -> UCLASS(BlueprintType)
	class PROJECTC_API UDataAsset_InputConfig : public UDataAsset

	로 바꾸니 열려서 이렇게 그냥 수정함. */

class UInputAction;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorInputActionConfig
{
	GENERATED_BODY()

public:
	// 입력액션과 태그를 매핑하기 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputAction* InputAction = nullptr;

};
/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTC_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// Enhanced Input의 Mapping Context를 의미 
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* DefaultMappingContext;

	// 구조체 배열. 태그<>액션 매핑과 에디터에서 순서대로 띄워 수정할 수 있따. 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FWarriorInputActionConfig> NativeInputActions;

	// 배열을 순회하면서 매개변수와 같은 InputTag를 가진 구조체를 찾고, 그에 대응하는 UInputAction*을 반환한다. 
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
};
