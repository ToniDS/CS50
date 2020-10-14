SELECT name FROM(
SELECT person_id
FROM directors INNER JOIN
(SELECT movie_id FROM ratings WHERE rating >9.0) AS ratings_9
ON directors.movie_id = ratings_9.movie_id) AS directors_9
INNER JOIN people on directors_9.person_id = people.id;