// Fill out your copyright notice in the Description page of Project Settings.

#include "CompatSplashWidget.h"

void UCompatSplashWidget::StartSplashAnim()
{
	CmdSplashStart.Broadcast();
}

void UCompatSplashWidget::StopSplashAnim()
{
	CmdSplashStop.Broadcast();
}

void UCompatSplashWidget::Reset()
{
	CmdSplashReset.Broadcast();
}

void UCompatSplashWidget::CallSplashStart()
{
	OnSplashStart.Broadcast();
}

void UCompatSplashWidget::CallSplashFinished()
{
	OnSplashFinished.Broadcast();
}

void UCompatSplashWidget::CallMoveNext(int32 index)
{
	OnMoveNext.Broadcast(index);
}
