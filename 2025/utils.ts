const inputFile = "./input.txt";

export async function readInput(path = inputFile) {
  try {
    const file = Bun.file(path);
    return await file.text();
  } catch (error) {
    console.error("Error reading file:", error);
  }
}
