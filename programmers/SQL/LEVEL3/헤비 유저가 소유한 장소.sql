select B.id, B.name, B.host_id
from (SELECT host_id
    from places
    group by host_id
    having count(host_id) > 1) A left join places B on A.host_id = B.host_id
order by B.id asc