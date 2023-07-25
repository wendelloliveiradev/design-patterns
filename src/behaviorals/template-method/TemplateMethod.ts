import {CommonCourseCreation} from './Interfaces';

// video course creation implements its own metadata and content definition 
class CreateVideoCourse extends CommonCourseCreation {
    protected defineCourseMetadata(): void {
        console.log('Defining video course metadata');
    }
    protected defineCourseContent(): void {
        console.log('Defining video course content');
    }
}

// text course creation implements the metadata and the content differently from video course creation
class CreateTextCourse extends CommonCourseCreation {
    protected defineCourseMetadata(): void {
        console.log('Defining text course metadata');
    }
    protected defineCourseContent(): void {
        console.log('Defining text course content');
    }
}

// Client Code
const videoCourse = new CreateVideoCourse();
videoCourse.createCourseTemplateMethod();

const textCourse = new CreateTextCourse();
textCourse.createCourseTemplateMethod();
