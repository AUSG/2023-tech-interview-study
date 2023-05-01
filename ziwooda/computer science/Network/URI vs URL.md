# URL & URI

<img src="https://user-images.githubusercontent.com/70079416/235417560-e58c03be-89b8-47c1-80d3-d89ff97d70ee.png" width=60% height=60%>

출처: [https://hanamon.kr/네트워크-기본-url-uri-urn-차이점/](https://hanamon.kr/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-%EA%B8%B0%EB%B3%B8-url-uri-urn-%EC%B0%A8%EC%9D%B4%EC%A0%90/)

<br>

## URI

- Uniform Resource Identifier, 통합 자원 식별자
- 인터넷의 자원을 식별할 수 있는 문자열이자 인터넷에 있는 자원을 나타내는 유일 주소
- URL, URN 개념 모두 포함

## URL

- Uniform Resource Locator
- 네트워크 상에서 웹페이지, 이미지, 동영상 등의 파일이 위치한 정보
- FTP, SFTP 등 다른 프로토콜에서 사용
- REST API: 더 효율적으로 리소스에 접근하기 위해 등장한 url 작성 방법론의 하나
- URI와 개념의 거의 동일

<br>

### Summary
**❗️URL과 URN❗️**

URL: 어떻게 리소스를 얻을 것이고, 어디에서 가져와야 하는지 명시하는 URI
URN: 리소스를 어떻게 접근할 것인지 명시하지 않고 경로와 리소스 자체를 특정하는 URI

<br>

## URN

- Uniform Resource Name
- URI의 표준 포맷 중 하나로 이름으로 리소스 특정하는 URI
- 프로토콜을 제외한 리소스 네임
- 리소스를 영구적이고 유일하게 식별할 수 있는 URI
- 리소스 자체에 부여된 영구적이고 유일한 이름, 불변
- 실제 자원을 찾으려면 URN을 URL로 변환하여 이용

<br>

http  ://  opentutorials.org  :  3000  /  main  ?  id=HTML&page=12

⇒ {protocol} :// {host(domain)} : {port} / {path} ? {query string}

URI: entire address

URL: protocol ~ path

URN: host ~ query string

<br>
> URI는 URL이다 ⭕
> URL을 포함한 URI ⭕
> URL은 URI이다 ❌
