# KiBeomChung-ShipDrivingSimulationProject
인턴쉽(현장실습) 기간동안에 언리얼엔진을 이용한 선박 항해 시뮬레이션 프로젝트입니다.


### 요구사항
<img width="858" alt="image" src="https://user-images.githubusercontent.com/70502804/190242665-204cb5c3-217d-4938-a934-31fbcdaa39f5.png">

### 프로젝트 구현 기능 설명

#### 1-1. 키보드를 입력을 통한 선박의 이동
<img width="455" alt="image" src="https://user-images.githubusercontent.com/70502804/190351571-a4b1bf52-715d-49f6-ac3f-2db4d6aa939f.png">

* 설정 -> 프로젝트 세팅 에 들어가서 앞으로 가기 위한 키보드 입력을 설정, 좌우 방향전환을 위한 키보드 입력 설정
* 각각 이름은 MoveForward, MoveRight로 설정. 이 이름은 나중에 C++ 코드로 작성할때 필요하므로 잘 기억해야함.
* MouseYaw, MousePithch는 4번째 기능을 위한 입력. 지금은 신경쓰지 않아도 된다.

#### 1-2. MoveForward & 가속도 표현
<img width="952" alt="image" src="https://user-images.githubusercontent.com/70502804/190352486-c2b38b16-4801-44ac-ace5-c05213b94ddb.png">

##### 구현한 Blueprint 설명
* MeshComponent는 Boat를 의미. 
* 현재 위치하고있는 World의 z축 Rotation 만 가져옴.<br> (z축이 기준이 되야 상하좌우가 구별. Get Forward Vector 함수를 가져와서 MoveForward 에 해당하는 키보드 입력되었을때 그때의 AxisValue 만큼의 크기로 전진, Get Forward Vector 함수를 통해 리턴된 Rotation의 방향으로 World Direction 설정. 그 뒷부분은 MoveRight와 연결 표현.)

<img width="952" alt="image" src="https://user-images.githubusercontent.com/70502804/190444220-c02fe4d5-b0f8-434f-88d0-9ba9e4870367.png">

##### 구현한 Blueprint 설명
* Floating Pawn Movement 컴포넌트를 Boat 뷰포트에서 추가. 
* 그래서 블루프린트 이벤트로 와서는 Floating Pawn Movement 컴포넌트의 X축 속도, Y축 속도를 가져오고(가속도 담당), Get Physics Linear Velocity에서는 Z축 값을 가져옴. 
* 그래서 Get Physics Linear Velocity 의 Z축값과 Floating Pawn Movement 속도 X,Y값을 Lerp 함수의 B와 연결, Get Physics Linear Velocity 의 모든 값은 A와 연결하여 Alpha 값을 0.9로 설정(느리게 회전하기 위해)
* Lerp 함수는 A값과 B 값의 Alpha 비율만큼의 값을 Value값으로 리턴. 
* 이 Value값을 Set Physics Linear Velocity 함수를 통해 가속도 설정.


<img width="641" alt="image" src="https://user-images.githubusercontent.com/70502804/190444979-cba9b3c7-a145-4bce-901a-3e042be675b3.png">

##### 구현한 Blueprint 설명
* Boat BP의 뷰포트의 디테일 패널에서 FloatingPawnMovement 컴포넌트를 통해가속도 설정하는 부분 
<br> (Buoyancy는 부력에 해당하는 부분으로, 선박이 물에 뜨기 위해 Buoyancy  컴포넌트를 Boat에 추가한 것.)



