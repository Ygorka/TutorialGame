// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorial/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APlayerCharacter::APlayerCharacter() : Super() {

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);

	


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->bUsePawnControlRotation = true;

	Camera->bUsePawnControlRotation = false;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* MyPlayerInput){
	
	Super::SetupPlayerInputComponent(MyPlayerInput);

	MyPlayerInput->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	MyPlayerInput->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	MyPlayerInput->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput);
	MyPlayerInput->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);

	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	MyPlayerInput->BindAction("StopJump", IE_Released, this, &APlayerCharacter::StopJump);


}

void APlayerCharacter::MoveForward(float Value) {

	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void APlayerCharacter::MoveRight(float Value) {
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void APlayerCharacter::Jump() {
	bPressedJump = true;
}

void APlayerCharacter::StopJump() {
	bPressedJump = false;
}
