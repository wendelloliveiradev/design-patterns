// Class definition for the course creation that contains the Template Method structure
export abstract class CommonCourseCreation {
    protected createCourse(): void {
        console.log('Creating course');
    }
    protected abstract defineCourseMetadata(): void;
    protected abstract defineCourseContent(): void;
    protected publishCourse(): void {
        console.log('Publishing course');
    }

    public createCourseTemplateMethod(): void {
        this.createCourse();
        this.defineCourseMetadata();
        this.defineCourseContent();
        this.publishCourse();
    }
} 