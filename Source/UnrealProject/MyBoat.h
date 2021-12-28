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
	float RotationSpeed; //회전할때의 속도

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator RotationRate; //카메라가 회전하고 있는 각도

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator InitialRotation; //처음 선박의 회전각도

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTrue; //MoveForwar에 해당하는 키보드 입력을 했을때 true

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int isForward; 

	FRotator NowLocation; //선박의 현재위치의 각도를 저장할 변수
	FRotator LaterLocation; // 선박의 나중 위치의 각도를 저장할 변수

	UPROPERTY(EditAnywhere)
	class UCameraComponent* FrontCamera;  //카메라 컴포넌트 변수

	//UPROPERTY(EditAnywhere)
	//class UCameraComponent* RightCamera;

	//UPROPERTY(EditAnywhere)
	//class UCameraComponent* LeftCamera;
	
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USpringArmComponent* FrontSpringArm; //카메라에 연결할 스프링암 변수

	//UPROPERTY(VisibleAnywhere, Category = "Mesh")
	//class USpringArmComponent* RightSpringArm;

	//UPROPERTY(VisibleAnywhere, Category = "Mesh")
	//class USpringArmComponent* LeftSpringArm;

	FVector2D MouseInput; //MouseYaw, Pitch를 통해 받은 값을 저장할 벡터 변수

	//FORCEINLINE USpringArmComponent* GetSpringArmComponent()
	//{
	//	return FrontSpringArm; 
	//}
	//
	//FORCEINLINE void SetSpringArmComponent(USpringArmComponent* InSpringArm)
	//{ 
	//	FrontSpringArm = InSpringArm;
	//}

private:

	UFUNCTION(BlueprintCallable) //bTrue 변수의 값을 true로 바꾸는 함수
	void IsTrue();

	UFUNCTION(BlueprintCallable) //bTrue 변수의 값을 fasle로 바꾸는 함수
	void IsFalse();

	UFUNCTION(BlueprintCallable)
	bool bIsOne(float Value); //Value값이 1인지 확인하는 함수, 1이면 LaterLocation 의 값을 변경, 아니면 NowLocation 값 변경


	void MoveRight(float Value); // 좌우 키보드 입력 받는 함수

	void MouseYaw(float axis); //마우스 입력 함수 (카메라 전환)
	void MousePitch(float axis); //마우스 입력 함수 (카메라 전환)

	//void RightCameraChange(float Value);
	//void LeftCameraChange(float Value);
	//void FrontCameravChange(float Value);

};
