CREATE VIEW products_for_recipes(recipe, product, quantity) AS
    SELECT r.name, p.name, SUM(i.quantity) ||' '||unit
    FROM recipes r JOIN recipes_ingredients i 
        ON r.recipe_id = i.recipe_id
        JOIN products p
        ON i.product_id = p.product_id
        GROUP BY r.name, p.name;
        
SELECT *
FROM recipes;

CREATE VIEW products_for_recipes(recipe, product, quantity) AS
    SELECT r.name, p.name, SUM(i.quantity) ||' '||i.unit
    FROM recipes r JOIN recipes_ingredients i 
        ON r.recipe_id = i.recipe_id
        JOIN products p
        ON i.product_id = p.product_id
    GROUP BY r.name, p.name, i.unit
    ORDER BY r.name, p.name;
        --GROUP BY r.name p.name;

SELECT *
FROM products_for_recipes;

ALTER TABLE reviews
MODIFY CONSTRAINT rat_chk CHECK(rating >=0 AND <=5);