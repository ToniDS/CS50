SELECT title
FROM stars
INNER JOIN (SELECT * FROM people 
            WHERE name = "Johnny Depp" AND
            name = "Helena Bonham Carter") AS peeps
            ON peeps.id = stars.person_id
INNER JOIN movies ON movies.id = stars.movie_id;