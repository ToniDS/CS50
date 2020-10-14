SELECT name
FROM
(SELECT DISTINCT person_id
FROM (SELECT id FROM movies
WHERE year = 2004) AS movies_2004
INNER JOIN stars ON movies_2004.id=stars.movie_id) AS person_2004
INNER JOIN people on person_2004.person_id = people.id
ORDER BY birth;