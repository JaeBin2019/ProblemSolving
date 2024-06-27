/*
	https://school.programmers.co.kr/learn/courses/30/lessons/151136
	평균 일일 대여 요금 구하기
	차 종이 SUV 인 차량의 요금의 평균을 구하는 문제

*/
SELECT ROUND(AVG(DAILY_FEE))
FROM CAR_RENTAL_COMPANY_CAR
WHERE 1=1
AND CAR_TYPE='SUV'