pipeline {
    agent {
        docker {
            image 'gcc:latest'
        }
    }

    triggers {
        pollSCM('H/3 * * * *')
    }

    stages {
        stage('Build') {
            steps {
                sh 'cd tools && make'
            }
        }

        stage('Run Tests') {
            steps {
                sh 'cd tools && make test'
            }
        }

        stage('Archive') {
            steps {
                archiveArtifacts artifacts: 'tools/app', fingerprint: true
            }
        }
    }

    post {
        success {
            echo 'All tests passed ✅'
        }
        failure {
            echo 'Tests failed ❌'
        }
    }
}