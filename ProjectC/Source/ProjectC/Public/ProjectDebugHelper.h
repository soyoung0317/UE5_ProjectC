#pragma once

namespace Debug
{
	static void Print(const FString& Msg, const FColor& Color = FColor::MakeRandomColor(), int32 Inkey = -1)
	{
		if (GEngine)
		{
			// 화면에 디버그 메세지 표시하기 : 키 , 지속시간, 색상, 메세지, 
			GEngine->AddOnScreenDebugMessage(Inkey, 7.f, Color, Msg);

			UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
		}
	}
}