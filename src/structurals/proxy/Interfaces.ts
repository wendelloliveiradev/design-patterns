export interface FileManagementSystem {
    readFile(path: string): string;
    writeFile(path: string, content: string): void;
}