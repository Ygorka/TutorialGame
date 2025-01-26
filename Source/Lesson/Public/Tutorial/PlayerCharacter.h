// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tutorial/MainCharacter.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class LESSON_API APlayerCharacter : public AMainCharacter
{
	GENERATED_BODY()
public:

	APlayerCharacter();

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	virtual void SetupPlayerInputComponent(class UInputComponent* MyPlayerInput) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Jump();
	void StopJump();
};
