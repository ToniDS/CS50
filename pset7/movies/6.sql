SELECT avg(rating) 
    FROM (SELECT id
            FROM movies 
            WHERE year = 2012) As movies_2012
            INNER JOIN
            ratings on ratings.movie_id = movies_2012.id;