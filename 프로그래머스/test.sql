SELECT
   A.b_NO, 
   A.a_NO, 
   A.X_CODE, 
   A.Y_CODE, 
   A.INQUIRY_CONTENT,
   A.LINEUP_NO
FROM A
/* X_LINEUP_NO 과 하위역량 Y_LINEUP_NO 에 대한 정렬은 sort02() 에서 수행한다 */
ORDER BY
    LINEUP_NO,
    a_NO