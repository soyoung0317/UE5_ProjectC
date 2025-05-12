// Fill out your copyright notice in the Description page of Project Settings.
// 프로젝트 전반에서 사용할 InputTag를 선언,정의한다. 
#pragma once

#include "NativeGameplayTags.h"

namespace ProjectGameplayTags
{
	/** Input Tags **/
	// PROJECTC_API : 다른 모듈(플러그인이나 게임 모듈)에서도 이 태그 변수를 참조할 수 있도록 심볼(export)을 보장해 주는 매크로
	// 이 변수를 DLL 경계 밖에서도 링크할 수 있게 __declspec(dllexport/dllimport) 플래그를 붙여 주는 역할.

	PROJECTC_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move) // 외부에 선언된 전역변수를 만들겠다고 컴파일러에게 알려줌
	PROJECTC_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)
}