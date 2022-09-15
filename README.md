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

