pragma Singleton

import QtQuick 2.0
import QtShark.Images.private 1.0

Item {
    ImagesBackend {
        id: backend
    }

    function load(id, filename) {
        return backend.load(id, filename);
    }

    function release(id) {
        return backend.release(id);
    }
}
