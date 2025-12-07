@extends('layouts.app')

@section('content')

    {{-- Pesan sukses --}}
    @if (session('success'))
        <div class="alert alert-success">
            {{ session('success') }}
        </div>
    @endif

    {{-- Card Add New Task --}}
    <div class="card mb-4">
        <div class="card-header fw-semibold">Add New Task</div>
        <div class="card-body">
            <form action="{{ route('tasks.store') }}" method="POST">
                @csrf

                <div class="mb-3">
                    <label class="form-label">Task Name</label>
                    <input type="text" name="name"
                           class="form-control @error('name') is-invalid @enderror"
                           value="{{ old('name') }}">
                    @error('name')
                        <div class="invalid-feedback">{{ $message }}</div>
                    @enderror
                </div>

                <div class="mb-3">
                    <label class="form-label">Description</label>
                    <textarea name="description" rows="3"
                              class="form-control @error('description') is-invalid @enderror">{{ old('description') }}</textarea>
                    @error('description')
                        <div class="invalid-feedback">{{ $message }}</div>
                    @enderror
                </div>

                <button type="submit" class="btn btn-primary">Add Task</button>
            </form>
        </div>
    </div>

    {{-- List Task --}}
    @if ($tasks->isEmpty())
        <div class="alert alert-info">No task available</div>
    @else
        @foreach ($tasks as $task)
            <div class="card mb-2">
                <div class="card-body d-flex justify-content-between align-items-start">
                    <div>
                        <h6 class="mb-1">{{ $task->name }}</h6>
                        <p class="mb-1 small text-muted">{{ $task->description }}</p>

                        @if ($task->status === 'pending')
                            <span class="badge bg-warning text-dark">Pending</span>
                        @else
                            <span class="badge bg-success">Completed</span>
                        @endif
                    </div>

                    <div class="ms-3 d-flex flex-column gap-1">
                        <a href="{{ route('tasks.edit', $task->id) }}"
                           class="btn btn-sm btn-outline-secondary">Edit</a>

                        <form action="{{ route('tasks.destroy', $task->id) }}"
                              method="POST"
                              onsubmit="return confirm('Delete this task?')">
                            @csrf
                            @method('DELETE')
                            <button type="submit" class="btn btn-sm btn-danger">
                                Delete
                            </button>
                        </form>
                    </div>
                </div>
            </div>
        @endforeach
    @endif

@endsection
