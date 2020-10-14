SELECT title
FROM (
SELECT movie_id
FROM (SELECT id
FROM people WHERE name = "Chadwick Boseman") AS chad 
INNER JOIN stars ON stars.person_id = chad.id) AS chad_mov
INNER JOIN ratings ON chad_mov.movie_id = ratings.movie_id 
INNER JOIN movies ON ratings.movie_id = movies.id
ORDER BY rating DESC
LIMIT 5;