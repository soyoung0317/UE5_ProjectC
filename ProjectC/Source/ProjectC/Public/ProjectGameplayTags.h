// Fill out your copyright notice in the Description page of Project Settings.
// 프로젝트 전반에서 사용할 InputTag를 선언,정의한다. 
#pragma once

#include "NativeGameplayTags.h"

namespace ProjectGameplayTags
{
	/** Input Tags **/
	// PROJECTC_API :  만약 프로젝트가 모듈(플러그인, 게임 모듈 등)으로 분리되어 있을 때,
	// 이 태그 변수를 다른 모듈에서도 쓸 수 있도록 __declspec(dllexport/dllimport) 플래그를 붙여주는 매크로입니다.
    // 쉽게 말해 “DLL 경계 밖에서도 연결(link)해 주세요” 라는 뜻

	PROJECTC_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move) // 외부에 선언된 전역변수를 만들겠다고 컴파일러에게 알려줌
	PROJECTC_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look)
}