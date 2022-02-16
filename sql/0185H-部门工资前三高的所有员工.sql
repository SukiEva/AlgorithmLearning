select 
    d.name as Department, e1.name as Employee, e1.salary as Salary
from 
    Employee e1, Department d
where
    e1.DepartmentId = d.Id
and 3 > (
    select count(distinct e2.salary)
    from Employee e2
    where e1.salary<e2.salaryx
    and e1.DepartmentId=e2.DepartmentId
)
order by d.name, salary desc;