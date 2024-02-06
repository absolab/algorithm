SELECT A.animal_id, a.name
from animal_ins A join animal_outs B on a.animal_id = b.animal_id
order by (b.datetime - a.datetime) desc
limit 2