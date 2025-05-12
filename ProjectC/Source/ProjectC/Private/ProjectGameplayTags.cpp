// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectGameplayTags.h"

namespace ProjectGameplayTags
{
	/** Input Tags **/
	// 헤더에서 extern으로 선언한 InputTag_T를 실제변수 FGameplayTag로 정의하고, 
	// 내부적으로 UGameplayTagsManager::Get().RequestGameplayTag("InputTag.Move") 를 호출해 태그를 초기화해 줍니다.

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move")
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look")
}