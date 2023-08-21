import { FileSystem } from "./Interfaces";

// Composite File System Directory
class CompositeFileSystemDirectory implements FileSystem {
    private children: FileSystem[] = [];

    constructor(private name: string) {}

    public showName(): void {
        console.log(this.name);
        this.children.forEach((child) => {
            child.showName();
        });
    }

    public add(child: FileSystem): void {
        this.children.push(child);
    }

    public remove(child: FileSystem): void {
        this.children = this.children.filter((c) => c !== child);
    }
}

// Composite File System File
class CompositeFileSystemFile implements FileSystem {
    constructor(private name: string) {}

    public showName(): void {
        console.log(this.name);
    }
}

// Client Code
const root = new CompositeFileSystemDirectory("root");
const home = new CompositeFileSystemDirectory("home");
const user = new CompositeFileSystemDirectory("user");
const file1 = new CompositeFileSystemFile("file1");
const file2 = new CompositeFileSystemFile("file2");
const file3 = new CompositeFileSystemFile("file3");

root.add(home);
home.add(user);
user.add(file1);
user.add(file2);
user.add(file3);

root.showName();
