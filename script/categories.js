// Sample data for categories
const categories = [
  // { id: 1, name: "Basics" },
  // { id: 2, name: "Sorting Techniques" },
  { id: 3, name: "Array Problems" },
  // { id: 4, name: "Binary Search" },
  // { id: 5, name: "Strings" },
  // { id: 6, name: "LinkedList" },
  // { id: 7, name: "Recursion" },
  // { id: 8, name: "Bit Manipulation" },
  // { id: 9, name: "Stack and Queues" },
  // { id: 10, name: "Sliding Window & Two Pointer" },
  // { id: 11, name: "Heaps" },
  // { id: 12, name: "Greedy Algorithms" },
  // { id: 13, name: "Binary Trees" },
  // { id: 14, name: "Binary Search Trees" },
  { id: 15, name: "Graphs" },
  { id: 16, name: "Dynamic Programming" },
  // { id: 17, name: "Tries" },
  // { id: 18, name: "Advanced Strings" }
];
    // Populate the category list
    window.onload = () => {
      const categoryList = document.getElementById("categoryList");

      categories.forEach(category => {
        const categoryDiv = document.createElement("div");
        categoryDiv.classList.add("bg-white", "p-4", "rounded", "shadow", "hover:bg-gray-100", "cursor-pointer");
        categoryDiv.innerHTML = `<h3 class="text-xl font-bold">${category.name}</h3>`;

        // On clicking a category, redirect to subcategories.html with categoryId in URL
        categoryDiv.addEventListener("click", () => {
          window.location.href = `subcategories.html?categoryId=${category.id}`;
        });

        categoryList.appendChild(categoryDiv);
      });
    };


