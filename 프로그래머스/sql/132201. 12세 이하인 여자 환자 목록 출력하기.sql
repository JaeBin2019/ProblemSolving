/*
	https://school.programmers.co.kr/learn/courses/30/lessons/132201
	12세 이하인 여자 환자 목록 출력하기
	
	PATIENT 테이블에서 12세 이하인 
	여자환자의 환자이름, 환자번호, 성별코드, 나이, 전화번호를 조회하는 SQL문을 작성해주세요. 
	이때 전화번호가 없는 경우, 'NONE'으로 출력시켜 주시고 
	결과는 나이를 기준으로 내림차순 정렬하고, 나이 같다면 환자이름을 기준으로 오름차순 정렬해주세요.

	COALESCE : 앞의 값이 NULL 이면 뒤의 값을 택하는 함수. 인자 여러개 가능
	
*/

SELECT
    PT_NAME,
    PT_NO,
    GEND_CD,
    AGE,
    COALESCE(TLNO, 'NONE') AS TLNO
FROM PATIENT
WHERE 1=1
    AND AGE <= 12
    AND GEND_CD = 'W'
ORDER BY
    AGE DESC,
    PT_NAME
