// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize();

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* JoinMenuJoinButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UEditableTextBox* IPAddressField;

private:
	/// Functions
	UFUNCTION(BlueprintCallable)
	void HostServer();

	UFUNCTION(BlueprintCallable)
	void JoinServer();

	UFUNCTION(BlueprintCallable)
	void QuitPressed();
	/// *******
};
