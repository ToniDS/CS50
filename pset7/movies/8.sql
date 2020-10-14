SELECT name 
FROM (
    SELECT person_id
    FROM (SELECT id FROM movies
        WHERE title = "Toy Story") AS toy 
        INNER JOIN stars
        ON stars.movie_id=toy.id) AS starstruck
    INNER JOIN people 
    ON starstruck.person_id = people.id;