SELECT animal_id, name, 
case
    when sex_upon_intake like "%neutered%" then "O"
    when sex_upon_intake like "%spayed%" then "O"
    else "X"
end as "Áß¼ºÈ­"
from animal_ins
order by animal_id asc