 const subcategories = {
      3: [
        { id: 5, name: "Easy" },
        { id: 6, name: "Medium" },
        { id: 7, name: "Hard" }
      ],
      15: [
        { id: 40, name: "Learning" },
        { id: 41, name: "Problems on BFS/DFS" }
      ],
      16: [
        { id: 46, name: "1D" },
        { id: 47, name: "2D/3D DP and DP on Grids" }
      ]
    };

    // Get the category ID from the URL
    const urlParams = new URLSearchParams(window.location.search);
    const categoryId = urlParams.get("categoryId");

    // Populate the subcategory list
    window.onload = () => {
      const subcategoryList = document.getElementById("subcategoryList");
      const selectedSubcategories = subcategories[categoryId];

      if (selectedSubcategories) { // Check if subcategories exist for the selected category
        selectedSubcategories.forEach(subcategory => {
          const subcategoryDiv = document.createElement("div");
          subcategoryDiv.classList.add("bg-white", "p-4", "rounded", "shadow", "hover:bg-gray-100", "cursor-pointer");
          subcategoryDiv.innerHTML = `<h3 class="text-xl font-bold">${subcategory.name}</h3>`;

          // On clicking a subcategory, redirect to problems.html with subcategoryId in URL
          subcategoryDiv.addEventListener("click", () => {
            window.location.href = `problems.html?subcategoryId=${subcategory.id}&categoryId=${categoryId}`;
          });

          subcategoryList.appendChild(subcategoryDiv);
        });
      } else {
        subcategoryList.innerHTML = "<p>No subcategories available for this category.</p>";
      }
    };
