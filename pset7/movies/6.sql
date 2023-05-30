/*
Write a SQL query to determine the average rating of all movies released in 2012.
  - Your query should output a table with a single column and a single row
    (not including the header) containing the average rating.
*/
SELECT avg(ratings.rating)
FROM movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE year = "2012";
