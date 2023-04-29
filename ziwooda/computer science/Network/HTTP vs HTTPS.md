# HTTP

**_HyperText Transfer Protocol, 클라이언트와 서버 간 통신을 위한 통신 규칙 및 프로토콜_**

⍥ OSI 7계층 중 애플리케이션 계층(L7)에 해당되는 프로토콜

⍥ 클라이언트가 웹 사이트에 HTTP 요청을 전송하면, 서버는 HTTP 응답으로 요청에 대한 응답 처리

- 서버의 HTTP 응답 ⇒ 200(success), 404(not found), 400(bad request), 500(Internal Server Error)

<br>

## HTTP 프로토콜의 작동 원리

⍥ 웹 서버와 사용자의 웹 브라우저는 데이터를 **일반 텍스트**로 교환 ⇒ **암호화되지 않은 데이터 전송**

⍥ `GET`, `PUT` 등의 요청으로 웹 사이트의 데이터를 확인 및 전송 가능

<br>

## HTTP/2, HTTP/3, HTTPS

⍥ HTTP/2와 HTTP/3은 프로토콜 자체를 업그레이드한 버전 → 데이터 전송 시스템을 수정하며 효율성 개선

- HTTP/2 : 텍스트 대신 바이너리 형태로 데이터 교환
- 서버가 새 HTTP 요청을 기다리는 대신, 클라이언트 캐시에 응답을 사전 전송 가능
- HTTP/3 : HTTP/2를 한 단계 발전시킨 버전, 실시간 스트리밍 및 기타 최신 데이터 전송 요구 사항을 효율적으로 지원

⍥ HTTPS → 데이터 보안을 업그레이드하여 최신 버전은 `SSL/TLS + HTTP/2`를 HTTPS로 사용

<br>

# HTTPS

**_HyperText Transfer Protocol Secure_**

⍥ HTTP는 암호화되지 않은 데이터를 전송하므로 제3자에 의해 데이터가 유출될 수 있다.

⇒ 이에 **보안 계층**을 더한 것이 HTTPS 프로토콜!

<br>

## HTTPS 프로토콜의 작동 원리

⍥ HTTPS는 **HTTP 요청 및 응답을 SSL/TLS에 결합**

- HTTPS 웹 사이트는 독립된 인증 기관(CA)에서 SSL/TLS 인증서를 획득
- 웹 사이트는 신뢰를 구축하기 위해서 데이터를 교환하기 전에 브라우저와 인증서를 교환

⍥ SSL 인증서에는 암호화 정보도 포함되어 있으므로 서버와 웹 브라우저는 암호화 or 스크램블된 데이터를 교환할 수 있다.

⍥ 이때! 신뢰성 있는 CA에서가 아닌 자체 인증서를 발급한 경우에는 안정성이 떨어질 수 있다!

<br>

## Overall Process

1. 사용자 웹 브라우저에 *`https://URL`* 형식으로 웹 접속
2. ➡️ 클라이언트(브라우저)는 서버의 SSL 인증서를 요청하여 사이트의 신뢰성 검증을 시도
3. ⬅️ 서버는 퍼블릭 키가 포함된 SSL 인증서를 회신
4. ➡️ 클라이언트(브라우저) 웹 사이트의 SSL 인증서의 유효성 검사하고 세션 키 발급
5. ➡️ 또한 퍼블릭 키를 사용하여 비밀 세션 키가 포함된 메시지를 암호화하고 서버에 전송
6. ⬅️ 웹 서버는 프라이빗 키로 메시지를 해독하고 세션 키 검색
7. 그 후, 세션 키를 암호화하고 브라우저에 승인 메시지 전송
8. ↔️ 브라우저와 웹 서버는 모두 동일 세션 키를 사용하여 메시지를 안전하게 교환할 수 있다!

<img src="https://user-images.githubusercontent.com/70079416/233945905-4623d84d-6cf0-44fd-b960-5ca3190bf310.png" width="60%" height="60%" />

<br>

## Why HTTPS instead of HTTP?

### 보안

HTTPS는 HTTP와 달리 암호화된 데이터를 전송하므로 사용자가 민감 데이터를 전송할 때에도 네트워크를 통한 데이터 유출 가능성이 없음을 확신할 수 있다.

### 권위

검색 엔진은 HTTPS보다 신뢰성이 더 낮은 HTTP 웹 페이지의 순위를 낮게 지정한다.

### 성능 및 분석

HTTPS 웹 애플리케이션은 HTTP 웹 애플리케이션보다 로드 속도가 더 빠르고, 참조 링크를 더 빠르게 추적할 수 있다.

<br>
<br>

## Comparison Table

<img src="https://user-images.githubusercontent.com/70079416/233945897-9f584f4e-884b-4dd9-b97e-d56b0a208c65.png" width="80%" height="80%" />

---

**⍢ References**

- [HTTP와 HTTPS - 전송 프로토콜 비교 - AWS](https://aws.amazon.com/ko/compare/the-difference-between-https-and-http/)

- [How Does HTTPS Work? RSA Encryption Explained](https://tiptopsecurity.com/how-does-https-work-rsa-encryption-explained/)