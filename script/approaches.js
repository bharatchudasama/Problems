// Sample data for approaches corresponding to problems
const approachesData = {
  4: [
    { id: 1, name: "Approach 1", file: "p1.cpp" },
    { id: 2, name: "Approach 2", file: "p2.cpp" },
    { id: 3, name: "Approach 3", file: "p3.cpp" },
  ]
  // Add other problem IDs and their approaches here
};

// Get the problem ID, subcategory ID, and category ID from the URL
const urlParams = new URLSearchParams(window.location.search);
const problemId = urlParams.get("problemId");
const subcategoryId = urlParams.get("subcategoryId");
const categoryId = urlParams.get("categoryId");

// Log the IDs to check if they're being correctly retrieved
console.log("problemId:", problemId);
console.log("subcategoryId:", subcategoryId);
console.log("categoryId:", categoryId);

// Populate the approach list
window.onload = () => {
  const approachList = document.getElementById("approachList");
  const selectedApproaches = approachesData[problemId];

  // Log the selectedApproaches to ensure data is being fetched correctly
  console.log("selectedApproaches:", selectedApproaches);

  if (selectedApproaches && selectedApproaches.length > 0) {
    selectedApproaches.forEach(approach => {
      const approachItem = document.createElement("li");
      approachItem.classList.add("text-blue-500", "cursor-pointer", "hover:underline");
      approachItem.innerText = approach.name;

      // On clicking an approach, redirect to the code page with categoryId, subcategoryId, and problemId
      approachItem.addEventListener("click", () => {
        window.location.href = `code.html?file=${approach.file}&categoryId=${categoryId}&subcategoryId=${subcategoryId}&problemId=${problemId}`;
      });

      approachList.appendChild(approachItem);
    });
  } else {
    approachList.innerHTML = "<p>No approaches available for this problem.</p>";
  }
};
