select a.id from Weather as a, Weather as b
where DATEDIFF(a.recordDate, b.recordDate) = 1
and a.temperature > b.temperature;