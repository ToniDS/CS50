SELECT title, rating 
FROM (SELECT title, id
    FROM movies 
    WHERE year = 2010) AS movies_2010
    INNER JOIN ratings ON movies_2010.id = ratings.movie_id
    ORDER BY rating DESC, title;