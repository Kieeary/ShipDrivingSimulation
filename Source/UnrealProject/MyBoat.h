// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyBoat.generated.h"

UCLASS()
class UNREALPROJECT_API AMyBoat : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyBoat();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boat Speed");
	float RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator RotationRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator InitialRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTrue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int isForward;

	FRotator NowLocation;
	FRotator LaterLocation;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* FrontCamera;

	//UPROPERTY(EditAnywhere)
	//class UCameraComponent* RightCamera;

	//UPROPERTY(EditAnywhere)
	//class UCameraComponent* LeftCamera;
	
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USpringArmComponent* FrontSpringArm;

	//UPROPERTY(VisibleAnywhere, Category = "Mesh")
	//class USpringArmComponent* RightSpringArm;

	//UPROPERTY(VisibleAnywhere, Category = "Mesh")
	//class USpringArmComponent* LeftSpringArm;

	FVector2D MouseInput;

	FORCEINLINE USpringArmComponent* GetSpringArmComponent()
	{
		return FrontSpringArm; 
	}
	
	FORCEINLINE void SetSpringArmComponent(USpringArmComponent* InSpringArm)
	{ 
		FrontSpringArm = InSpringArm;
	}

private:

	UFUNCTION(BlueprintCallable)
	void IsTrue();

	UFUNCTION(BlueprintCallable)
	void IsFalse();

	UFUNCTION(BlueprintCallable)
	bool bIsOne(float Value);


	void MoveRight(float Value);

	void MouseYaw(float axis);
	void MousePitch(float axis);

	//void RightCameraChange(float Value);
	//void LeftCameraChange(float Value);
	//void FrontCameravChange(float Value);

};
