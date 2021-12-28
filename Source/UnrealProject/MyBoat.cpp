// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoat.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFrameWork/SpringArmComponent.h" 
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyBoat::AMyBoat()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RotationSpeed = 50.0f;
	RotationRate = FRotator(0.0f, 0.0f, 0.0f);
	InitialRotation = FRotator(0.0f, 0.0f, 0.0f);

	MeshComponent->SetupAttachment(GetRootComponent()); //MeshComponent를 RootComponent에 연결하는 과정

	//FrontSpringArm의 위치, 회전, 길이 를 설정
	FrontSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("FrontSpringArm"));
	FrontSpringArm->SetupAttachment(MeshComponent);
	FrontSpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 900.0f));
	FrontSpringArm->SetRelativeRotation(FRotator(-30.0f, 0.f, 0.f));
	FrontSpringArm->TargetArmLength = 400.f;
	FrontSpringArm->bEnableCameraLag = true;
	FrontSpringArm->CameraLagSpeed = 3.0f;

	/*RightSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("RightSpringArm"));
	RightSpringArm->SetupAttachment(MeshComponent);
	RightSpringArm->SetRelativeRotation(FRotator(-30.0f, 60.0f, 0.f));
	RightSpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 900.0f));
	RightSpringArm->TargetArmLength = 400.f;
	RightSpringArm->bEnableCameraLag = true;
	RightSpringArm->CameraLagSpeed = 3.0f;

	LeftSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("LeftSpringArm"));
	LeftSpringArm->SetupAttachment(MeshComponent);
	LeftSpringArm->SetRelativeRotation(FRotator(-30.0f, -60.0f, 0.f));
	LeftSpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 900.0f));
	LeftSpringArm->TargetArmLength = 400.f;
	LeftSpringArm->bEnableCameraLag = true;
	LeftSpringArm->CameraLagSpeed = 3.0f;*/
	//FrontCamer를 FrontSpringArm에 연결
	FrontCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FrontCamera"));
	FrontCamera->SetupAttachment(FrontSpringArm, USpringArmComponent::SocketName);

	/*RightCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("RightCamera"));
	RightCamera->SetupAttachment(RightSpringArm, USpringArmComponent::SocketName);

	LeftCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("LeftCamera"));
	LeftCamera->SetupAttachment(LeftSpringArm, USpringArmComponent::SocketName);*/
	MouseInput = FVector2D(0.0f, 0.0f);

	//Pawn 클래스인 Boat를 플레이어 0으로 설정
	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AMyBoat::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyBoat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//NewYaw라는 Rotator변수를 통해 MouseInput의 값을 더하여 카메라의 시점 변화 (좌우)
	FRotator NewYaw = FrontSpringArm->GetComponentRotation();
	NewYaw.Yaw += MouseInput.X;
	FrontSpringArm->SetWorldRotation(NewYaw);

	//NewYaw라는 Rotator변수를 통해 MouseInput의 값을 더하여 카메라의 시점 변화 (위아래)
	FRotator NewPitch = FrontSpringArm->GetComponentRotation();
	NewPitch.Pitch = FMath::Clamp(NewPitch.Pitch + MouseInput.Y, -80.f, 0.f);
	FrontSpringArm->SetWorldRotation(NewPitch);

	//NewYaw.Yaw += CameraInput.X;
	//SetActorRotation(NewRotation);

	//FRotator NewSpringArmRotation = SpringArm->GetComponentRotation();
	//NewSpringArmRotation.Pitch = FMath::Clamp(NewSpringArmRotation.Pitch += CameraInput.Y, -80.f, -15.f);

	//SpringArm->SetWorldRotation(NewSpringArmRotation);
}

// Called to bind functionality to input
void AMyBoat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)

{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 프로젝트 세팅에서 설정한 이름에 해당하는 키보드 입력을 받았을때, 수행할 함수를 바인딩 하는 과정
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyBoat::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("MouseYaw"), this, &AMyBoat::MouseYaw);
	PlayerInputComponent->BindAxis(TEXT("MousePitch"), this, &AMyBoat::MousePitch);
}

//좌우 회전각도를 설정
void AMyBoat::MoveRight(float Value)
{
	InitialRotation = GetActorRotation();

	//UE_LOG(LogTemp, Warning, TEXT("Location: %f"), NowLocation.Yaw);
	//UE_LOG(LogTemp, Warning, TEXT("Rotation: %f, %f, %f"), GetOwner()->GetActorRotation());

	if (bTrue) // 앞으로가면서 회전할때는 회전에 제한이 없도록
	{
		AddActorLocalRotation(FRotator(0, Value * (RotationSpeed * 0.0003), 0));
	}
	   
	if (LaterLocation.Yaw - NowLocation.Yaw < 30.0f && LaterLocation.Yaw - NowLocation.Yaw > -30.0f) // 앞으로가지않고 회전하면 최대 30도까지만 회전이 가능하도록
	{
		UE_LOG(LogTemp, Warning, TEXT("Rotation: %f"), LaterLocation.Yaw - NowLocation.Yaw);
		AddActorLocalRotation(FRotator(0, Value * (0.0003 * RotationSpeed), 0));
	}

}

//마우스를 좌우로 움직일때 값을 받는 함수
void AMyBoat::MouseYaw(float Value)
{
	MouseInput.X = Value;
}

//마우스를 상하로 움질일때 값을 받는 함수
void AMyBoat::MousePitch(float Value)
{
	MouseInput.Y = Value;
}

void AMyBoat::IsTrue()
{
	bTrue = true;
}

void AMyBoat::IsFalse()
{
	bTrue = false;
}

//Value값이 1일때와 아닐때 수행하는 작업
bool AMyBoat::bIsOne(float Value)
{
	if (Value == 1)
	{
		LaterLocation = GetActorRotation();
		//UE_LOG(LogTemp, Warning, TEXT("Location: %f"), LaterLocation.Yaw);
		return true;
	}

	else
	{
		NowLocation = GetActorRotation();
		//UE_LOG(LogTemp, Warning, TEXT("Location: %f"), NowLocation.Yaw);
		return false;
	}

}
