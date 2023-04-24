# TCP

⍥ Transmission Control Protocol, 패킷을 **세그먼트 단위로** 처리하는 프로토콜_

⍥ 네트워크 계층의 **전송 계층**에서 사용하는 프로토콜

⍥ **Reliable Data Transmission : 신뢰성 있는 데이터 전송으로 안정성 제공**

⍥ 장치들 간 논리적인 접속을 위해 연결을 설정한 신뢰성을 보장하는 연결형 서비스 (connection-oriented protocol)

- 3-way handshaking으로 연결 및 4-way handshaking으로 연결 해제
- 웹 브라우저(HTTP), 메일, 파일 전송 등 신뢰성이 요구되는 애플리케이션에 사용

⍥ 데이터가 확실하게 송•수신될 수 있도록 속도를 조절하고, 순서를 보장 (ordered)

- UDP에 비해 상대적으로 속도가 느림

<br>

## TCP Header

<img src="https://user-images.githubusercontent.com/70079416/233922061-3d3912b7-de89-407b-b90d-d7ca8266f95d.png" width="80%" height="80%" />

<img src="https://user-images.githubusercontent.com/70079416/233922091-48a7a989-5936-4fe7-bcfa-620164120377.png" width="80%" height="80%" />

<br>

## TCP의 대표적인 3가지 제어

- 전송 데이터의 양을 조절하는 흐름제어
- 통신 중 데이터가 유실되거나 잘못 수신되었을 경우에 대처하기 위한 오류제어
- 네트워크 혼잡에 대처하기 위한 혼잡제어

### 1. **흐름제어 (Flow Control)**

---

> _송신 측과 수신 측의 데이터 처리 속도가 상이할 시 발생 가능한 오류에 대비하기 위해 전송되는 데이터 양을 조절하는 흐름 제어 기능_

- 송신 측의 속도가 빠르면, 수신 측 버퍼가 넘치는 오버플로우 문제 발생 가능
    
    ⇒ 윈도우 크기로 송신 측 데이터 전송량을 조절
    

해결방법1) **Stop and Wait** : 상대에게 데이터를 보낸 후 응답 신호를 받고 나서 다음 패킷을 보내는 방법

<img src="https://user-images.githubusercontent.com/70079416/233922097-2b22d32d-bdab-4742-be78-838cb43b7311.png" width="80%" height="80%" />

해결방법2) **Sliding Window** : 송신 측이 수신 측에서 받은 윈도우 크기를 참고하여 데이터 흐름을 제어하는 방법

⍥ 윈도우 크기 : 처리할 수 있는 데이터 양

⍥ 수신 측(sender)이 한 번에 처리 가능한 윈도우 크기 만큼의 데이터를 3-way handshaking할 때 송신 측(receiver)에 전달한다.

- 상대방에게 응답을 받지 않아도 범위 내에서 데이터를 전송 가능
- 패킷의 왕복시간이 크면 네트워크가 혼잡하다고 간주 ⇒ 윈도우 크기를 실제 버퍼보다 작게 설정
- 윈도우 크기는 통신 과정 중에 유동적으로 설정

<br>

### 2. 오류제어

---

> _TCP는 통신 중에 오류가 발생하면 해당 데이터를 재전송하고, 이때 재전송 기반 오류 제어인 ARQ(Automatic Repeat Request)를 사용_

⍥ 오류인지 알 수 있는 방법?

- 송신 측이 보낸 데이터가 유실된 경우
- 수신 측이 보낸 응답(ACK) 데이터가 유실되어 송신 측이 ACK를 받지 못한 경우
- 중복된 ACK를 받은 경우
- 수신 측이 부정 응답(NACK)을 보낸 경우

<br>

### 3. 혼잡 제어 (Congestion Control)

---

> _네트워크 내에 패킷 수가 과도하게 증가하는 혼잡 현상을 방지하고 제거하기 위한 제어 방법_

⬇️4가지의 혼잡제어 해결방법⬇️
<img src="https://user-images.githubusercontent.com/70079416/233922100-04c108d8-11d2-4572-9112-d7645025d010.png" width="60%" height="60%" />

해결방법 1) **AIMD** (Addictive Increase / Multiplicative Decrease)

⍥ 패킷을 하나씩 보내다가 문제가 발생하지 않으면 윈도우 크기를 +1 증가

- 그러나 패킷 전송에 실패하거나 timeout 발생 시, 전송 속도를 절반으로 줄임

⍥ 단점 : 처음에 전송 속도를 올리는 데 시간이 오래걸리고, 네트워크 혼잡 상황을 미리 감지하지 못하여 사전대처가 어렵다

해결방법 2) **Slow Start** (느린 시작)

⍥ ACK를 받을 때마다 각 패킷마다 윈도우 크기를 +1 증가시키고, 전송 속도는 지수 함수 꼴로 증가시킨다.

- 혼잡이 감지되면 윈도우 크기 -1 감소
- 한 번 혼잡 현상 발생 시 네트워크 수용량 예측이 가능
    
    ⇒ 혼잡 현상이 발생하는 윈도우 사이즈의 절반까지 지수 함수 꼴로 증가시키다가 그 후에는 +1 증가
    

해결방법 3) **Fast Retransmit** (빠른 전송)

⍥  수신자 측에서 먼저 도착해야 할 패킷이 아닌 다음 패킷을 받아도 ACK 패킷을 전송

- 지금까지 받은 데이터 중 연속되는 패킷의 마지막 순번 이후를 ACK 패킷에 실어 보낸다.
- 중복된 순번의 패킷을 3개 받으면 데이터 재전송하고, 이 상황을 혼잡하다고 판단하여 윈도우 크기를 줄인다.

<br>

# UDP

⍥ User Datagram Protocol, 데이터를 **데이터그램 단위로** 처리하는 프로토

⍥ 일방적인 데이터 전송, 비연결형 서비스 → 확인 응답이 불가능하여 TCP보다 신뢰도가 떨어짐

⍥ TCP에 비해 간단하여 용량이 가볍고, 순서가 보장되지 않으며, 송신 속도가 빠름 → **데이터의 신속성**

⍥ 데이터를 빠른 속도로 전송하고자 하는 애플리케이션에 사용

<br>

## UDP Header

<img src="https://user-images.githubusercontent.com/70079416/233922103-435f00ee-50f6-4ca6-a7ad-7f51d9c51ef5.png" width="80%" height="80%" />

<img src="https://user-images.githubusercontent.com/70079416/233922106-39c2e838-68fd-4951-b514-b93dc7967d7c.png" width="80%" height="80%" />

<br>

## Comparison Table

### 공통점

<img src="https://user-images.githubusercontent.com/70079416/233922110-9a1418f6-0003-48ae-86ac-db05248a8a95.png" width="80%" height="80%" />

### 차이점

<img src="https://user-images.githubusercontent.com/70079416/233922112-393e789c-ac8a-4b7b-9ed3-66fd1f9d0c89.png" width="80%" height="80%" />

### TCP와 UDP의 오류 해결 방법

<img src="https://user-images.githubusercontent.com/70079416/233922113-8b439b17-7904-46ac-840e-b84ef13c2db6.png" width="80%" height="80%" />
