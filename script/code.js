// Get the file name, category ID, subcategory ID, and problem ID from the URL
const urlParams = new URLSearchParams(window.location.search);
const fileName = urlParams.get("file");
const categoryId = urlParams.get("categoryId");
const subcategoryId = urlParams.get("subcategoryId");
const problemId = urlParams.get("problemId");

// Log the parameters for debugging
console.log("fileName:", fileName);
console.log("categoryId:", categoryId);
console.log("subcategoryId:", subcategoryId);
console.log("problemId:", problemId);

// Function to fetch and display the code from the file
function loadCode(filePath) {
  fetch(filePath)
    .then(response => {
      console.log("Response status:", response.status); // Log response status
      if (response.ok) {
        return response.text();
      } else {
        throw new Error("File not found");
      }
    })
    .then(code => {
      document.getElementById("codeBlock").textContent = code;
    })
    .catch(error => {
      document.getElementById("codeBlock").textContent = "Error: " + error.message;
      console.error("Error fetching code:", error); // Log error details
    });
}

// Construct the file path dynamically
const filePath = `DSA/${categoryId}/${subcategoryId}/${problemId}/${fileName}`; // Fixed path construction

// Log the filePath to check correctness
console.log("filePath:", filePath);

// Load the code when the page is loaded
window.onload = () => {
  loadCode(filePath);
};
