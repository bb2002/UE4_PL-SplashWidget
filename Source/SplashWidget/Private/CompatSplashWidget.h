// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CompatSplashWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCommandSplashStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCommandStop);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCommandReset);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSplashStart);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSplashFinished);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveNext, int32, Index);


/**
 * 
 */
UCLASS()
class UCompatSplashWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/**
	 * @Date 08.23 2019
	 Splash Plugin Delegates.
	*/
	UPROPERTY(BlueprintAssignable, Category = "SplashPlugin|Event")
	FOnSplashStart OnSplashStart;

	UPROPERTY(BlueprintAssignable, Category = "SplashPlugin|Event")
	FOnSplashFinished OnSplashFinished;

	UPROPERTY(BlueprintAssignable, Category = "SplashPlugin|Event")
	FOnMoveNext OnMoveNext;

	UPROPERTY(BlueprintAssignable, Category = "SplashPlugin|Commands")
		FCommandSplashStart CmdSplashStart;

	UPROPERTY(BlueprintAssignable, Category = "SplashPlugin|Commands")
		FCommandStop CmdSplashStop;

	UPROPERTY(BlueprintAssignable, Category = "SplashPlugin|Commands")
		FCommandReset CmdSplashReset;

	/**
	 * @Date 08.23 2019
	 Splash Plugin Command Functions.
	**/
	UFUNCTION(BlueprintCallable, Category = "SplashPlugin|Commands")
	void StartSplashAnim();

	UFUNCTION(BlueprintCallable, Category = "SplashPlugin|Commands")
	void StopSplashAnim();

	UFUNCTION(BlueprintCallable, Category = "SplashPlugin|Commands")
	void Reset();

protected:
	UFUNCTION(BlueprintCallable, Category = "SplashPlugin|Core", Meta=(AllowPrivateAccess = true))
		void CallSplashStart();

	UFUNCTION(BlueprintCallable, Category = "SplashPlugin|Core", Meta = (AllowPrivateAccess = true))
		void CallSplashFinished();

	UFUNCTION(BlueprintCallable, Category = "SplashPlugin|Core", Meta = (AllowPrivateAccess = true))
		void CallMoveNext(int32 index);
};
