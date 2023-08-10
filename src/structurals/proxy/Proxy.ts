import { FileManagementSystem } from "./Interfaces";

// This class represents the service that we want to proxy
class FileManagementSystemService implements FileManagementSystem {
    readFile(path: string): string {
        return `the content of the file, from ${path}`;
    }
    writeFile(path: string, content: string): void {
        console.log(`Writing ${content} to ${path}`);
    }
}

// This class represents the proxy
// We could break this proxy down into smaller objects with more specific responsibilities
// but for the sake of simplicity we'll keep it as a single class
class FileManagementSystemProxy implements FileManagementSystem {
    private file_management_system: FileManagementSystem = new FileManagementSystemService();
    private cache: Map<string, string[]> = new Map<string, string[]>();
    private log: string[] = [];
    private errors: string[] = [];

    readFile(path: string): string {
        return this.file_management_system.readFile(path);
    }
    writeFile(path: string, content: string): void {
        this.file_management_system.writeFile(path, content);
    }

    authenticateUser(username: string, password: string): boolean {
        if (username === 'admin' && password === 'admin')
            return true;

        return false;
    }

    authorizeUser(username: string, action: string): boolean {
        if (username === 'admin' && action !== '')
            return true;

        return false;
    }

    logUserAction(username: string, action: string): void {
        this.log.push(`User ${username} performed ${action}`);

        console.log(`User ${username} performed ${action}`);
    }

    logSystemError(error: string): void {
        this.errors.push(`System error: ${error}`);

        console.log(`System error: ${error}`);
    }

    cacheRequest(request: string): void {
        if (!this.cache.has("request"))
            this.cache.set("request", []);

        this.cache.get("request")?.push(request);

        console.log(`Caching request: ${request}`);
    }

    cacheResponse(response: string): void {
        if (!this.cache.has("response"))
            this.cache.set("response", []);

        this.cache.get("response")?.push(response);

        console.log(`Caching response: ${response}`);
    }
}

// Client code
const username: string = 'admin';
const password: string = 'admin';
const action: string = 'read';
const request: string = 'read file';
const response: string = 'file content';

const file_management_system: FileManagementSystemProxy = new FileManagementSystemProxy();

if (file_management_system.authenticateUser(username, password) && file_management_system.authorizeUser(username, action)) {
    file_management_system.readFile('path/to/file');
    file_management_system.writeFile('path/to/file', 'content');
    file_management_system.logUserAction(username, action);
    file_management_system.logSystemError('No Error');
    file_management_system.cacheRequest(request);
    file_management_system.cacheResponse(response);
}
