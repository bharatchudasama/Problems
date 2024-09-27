// Sample data for problems in a subcategory
const problems = {
  5: [],
  6: [],
  7: [],
  40: [
    { id: 1, name: "BFS" },
    { id: 2, name: "DFS" },
    { id: 3, name: "Connected components" }
  ],
  41: [],
  46: [
    { id: 4, name: "Climb stairs" },
    { id: 5, name: "Frog Jump" },
    { id: 6, name: "Frog Jump with k distances" },
    { id: 7, name: "Maximum sum of non-adjacent elements" },
    { id: 8, name: "House Robber" }
  ],
  47: []
};

// Get the subcategory ID from the URL
const urlParams = new URLSearchParams(window.location.search);
const subcategoryId = urlParams.get("subcategoryId");
const categoryId = urlParams.get("categoryId");

// Log the subcategoryId to check if it's being correctly retrieved
console.log("subcategoryId:", subcategoryId);

// Populate the problem list
window.onload = () => {
  const problemList = document.getElementById("problemList");
  const selectedProblems = problems[subcategoryId];

  // Log the selectedProblems to ensure data is being fetched correctly
  console.log("selectedProblems:", selectedProblems);

  if (selectedProblems && selectedProblems.length > 0) {  // Check if problems exist for the selected subcategory
    selectedProblems.forEach(problem => {
      const problemDiv = document.createElement("div");
      problemDiv.classList.add("bg-white", "p-4", "rounded", "shadow", "hover:bg-gray-100", "cursor-pointer");
      problemDiv.innerHTML = `<h3 class="text-xl font-bold">${problem.name}</h3>`;

      // On clicking a problem, redirect to the problem details page
      problemDiv.addEventListener("click", () => {
        window.location.href = `problem_details.html?problemId=${problem.id}&subcategoryId=${subcategoryId}&categoryId=${categoryId}`;
      });

      problemList.appendChild(problemDiv);
    });
  } else {
    problemList.innerHTML = "<p>No problems available for this subcategory.</p>";
  }
};
