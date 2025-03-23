

# leetcode 2115. Find All Possible Recipes from Given Supplies


# this is not optimized, for optimization we have to use graph
def findAllRecipes(recipes, ingredients, supplies):
    res = set()

    for j in range(len(recipes)):
        for i in range(len(ingredients)):
            if set(ingredients[i]).issubset(supplies):
                res.add(recipes[i])
                supplies.append(recipes[i])


    return list(res)

recipes = ["bread"]
ingredients = [["yeast","flour"]]
supplies = ["yeast","flour","corn"]

print(findAllRecipes(recipes, ingredients, supplies))

