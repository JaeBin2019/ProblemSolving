/*
	https://school.programmers.co.kr/learn/courses/30/lessons/131120
	3월에 태어난 여성 목록 출력하기

*/

SELECT 
    MEMBER_ID,
    MEMBER_NAME,
    GENDER,
    DATE_FORMAT(DATE_OF_BIRTH, '%Y-%m-%d') AS DATE_OF_BIRTH
FROM MEMBER_PROFILE
WHERE
        TLNO IS NOT NULL
    AND GENDER = 'W'
    AND MONTH(DATE_OF_BIRTH) = 3
ORDER BY
    MEMBER_ID